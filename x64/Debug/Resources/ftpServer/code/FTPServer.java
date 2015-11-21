package com.sdust.acmer.ftp;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.net.SocketException;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPClientConfig;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;

public class FTPServer {
	private File file;
	private int port;
	private String fileName;
	private String ipAddress;
	private String userName;
	private String passWord;
	static private String ftpPath;
	static private String localPath;
	
	/*
	 * 从配置文件中读取服务器信息以及传输路径
	 */
	public FTPServer(){
		localPath = "";
		try {
			File config = new File("config");
			FileReader fr;
			fr = new FileReader(config);
			BufferedReader br = new BufferedReader(fr);
			String string;
			int Case = 1;
			while((string = br.readLine()) != null){
				if(Case == 1)
					ipAddress = string;
				else if(Case == 2)
					port = Integer.parseInt(string);
				else if(Case == 3)
					userName = string;
				else if(Case == 4)
					passWord = string;
				else if(Case == 5)
					ftpPath = string;
				else if(Case == 6)
					localPath = string;
				Case++;	
			}
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public FTPServer(String _ip, int _port, String _user, String _pwd) {
		ipAddress = _ip;
		port = _port;
		userName = _user;
		passWord = _pwd;
	}
	
	public boolean sendFile(String _from, String _to, String _fileName){
		
		file = new File(_from + _fileName);
		fileName = _fileName;
		System.out.println(_from + _fileName);
		//连接
		FTPClient ftpClient = new FTPClient();
		ftpClient.setControlEncoding("UTF-8");
		FTPClientConfig conf = new FTPClientConfig(FTPClientConfig.SYST_NT);  
		conf.setServerLanguageCode("zh");
		
		try {
			ftpClient.connect(ipAddress, port);
		
			ftpClient.login(userName, passWord);
			
			int reply = ftpClient.getReplyCode();
			System.out.println(reply);
			
			if(!FTPReply.isPositiveCompletion(reply)){
				ftpClient.disconnect();
				return false;
			}
			
			System.out.println("The connection is successful!");
			
			ftpClient.setFileType(FTPClient.BINARY_FILE_TYPE);
			//ftpClient.setFileType(FTPClient.ASCII_FILE_TYPE);
			ftpClient.enterLocalPassiveMode();
			/*
			 * 文件的写入
			 */
			FileInputStream input = new FileInputStream(file);
			boolean res = ftpClient.storeFile(_to + fileName, input);
			
			input.close();
			ftpClient.logout();
			
			if(res)
				System.out.println("[" + fileName + "]" + " Documents send successfully!");
			else 
				System.out.println("[" + fileName + "]" + " Documents send failure!");
			return res;
			
		} catch (SocketException e) {
			e.printStackTrace();
		
		} catch (IOException e) {
			e.printStackTrace();
			
		} 
		return false;
	}
	
	public boolean receiveFile(String _from, String _to, String _fileName){
		
		fileName = _fileName;
		try {
			FTPClient ftpClient = new FTPClient();
			//设置编码以及文件格式
			ftpClient.setControlEncoding("UTF-8");
			FTPClientConfig conf = new FTPClientConfig(FTPClientConfig.SYST_NT);  
			conf.setServerLanguageCode("zh");
			ftpClient.connect(ipAddress, port);
			ftpClient.login(userName, passWord);
			
			int rely = ftpClient.getReplyCode();
			System.out.println(rely);
			/*
			 *	获取文件列表
			 * 	每次数据连接之前
			 * 	FTP client告诉FTP server开通一个端口来传输数据
			 */
			ftpClient.enterLocalPassiveMode();
			
			FTPFile[] files = ftpClient.listFiles(ftpPath);
			/*
			 *	ftpClient.makeDirectory("path");
			 *	for (int i = 0; i < files.length; i++) {
			 *		System.out.println(files[i].getName());
			 *}
			 */
			boolean bf = false;
			
			for(int i = 0; i < files.length; i++){
				if(files[i].getName().equals(fileName)){
					bf = true;
					break;
				}
			}
			
			if(bf){
				/*
				 * 文件的获取
				 */
				System.out.println("Have found user's data!");
				/*
				 * 本地文件
				 */
				file = new File(_to + fileName);
				FileOutputStream fos = new FileOutputStream(file);
				/*
				 * 服务器文件
				 */
				ftpClient.retrieveFile(_from + fileName, fos);
				fos.close();
				System.out.println("Documents have been received!");
				return true;
			}
			else{
				System.out.println("Can't find the user!");
				return false;
			}
			
		} catch (SocketException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		
		FTPServer ftpServer = new FTPServer();
		
		//ftpServer.sendFile(localPath, ftpPath, "sendfile");
		
		String user = "";
		if(args.length != 0)
			user = args[0];
		ftpServer.receiveFile(ftpPath, localPath, user);
		
		/*
		try {
			File file = new File(user);
			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);
			String string;
			while((string = br.readLine()) != null){
				System.out.println(string);
			}
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		*/
	}

}
