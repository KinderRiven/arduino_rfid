
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Vector;

public class MysqlServer {

	private String url;
    private Connection conn;
    private Statement stmt;

    final boolean DEBUG = false;

    private String ip;
    private String port;
    private String database;
    private String username;
    private String password;
    private String userFile;
    private String timeFile;

    private String outaddress;

    final int table_column = 7;

    Vector<String>vector;
    /*
     * jdbc:mysql://127.0.0.1:3306/rfid
     */
    public MysqlServer(){
    	ip = "127.0.0.1";
    	port = "3360";
    	database = "rfid";
    	username = "root";
    	password = "";
    	vector = new Vector<String>();
    }
    /*
     * Load Config
     */
	void loadConfig(){
		try {
			File file = new File("config");
			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);
			String line;
			int Case = 0;
			while((line = br.readLine()) != null){
				if(DEBUG)
					System.out.println(line);
				switch (Case) {
				//databae name
				case 0:
					database = line;
					break;
				//ip address
				case 1:
					ip = line;
					break;
				//port
				case 2:
					port = line;
					break;
				//username
				case 3:
					outaddress = line;
					break;
				case 4:
					userFile = line;
					break;
				case 5:
					timeFile = line;
					break;
				case 6:
					username = line;
					break;
				//password
				case 7:
					password = line;
					break;
				default:
					break;
				}
				Case++;
			}

			url = "jdbc:mysql://" + ip + ":" + port + "/" + database;
			if(DEBUG){
				System.out.println(url + " " + username  + " " + password);
				System.out.println(outaddress);
			}
			br.close();
			fr.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	/*
	 * Get Connect
	 */
	void getConnect(){
		try{
            Class.forName("com.mysql.jdbc.Driver");
            if(DEBUG)
            	System.out.println("成功加载MySQL驱动！");
        }catch(ClassNotFoundException e1){
        	if(DEBUG)
        		System.out.println("找不到MySQL驱动!");
            e1.printStackTrace();
        }
        try {
            conn = DriverManager.getConnection(url, username, password);
            stmt = conn.createStatement(); //创建Statement对象
            if(DEBUG)
            	System.out.println("成功连接到数据库！");
        } catch (SQLException e){
        	//System.out.println("连接到数据库失败！");
            e.printStackTrace();
        }
	}
	/*
	 * Close Connect
	 */
	void closeConnect(){
        try {
			stmt.close();
			conn.close();
			//System.out.println("成功关闭数据库连接！");
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	/*
	 * run sql
	 */
	void runSQL(String sql){
		try {
			ResultSet rs;
			rs = stmt.executeQuery(sql);
	        while(rs.next()){
	        	for(int i = 1; i < table_column; i++){
	        		vector.addElement(rs.getString(i));
	        	}
	        }
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	/*
	 * 	user
	 */
	void addUser(String cid){
		try {

			FileWriter writer = new FileWriter(userFile, true);
            writer.write(cid + '\n');
            writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/*
	 *  time
	 */
	void addTime(String cid){
		try {
			FileWriter writer = new FileWriter(timeFile, true);
			/*
			 * 	获得时间
			 */
			Date d = new Date();
			DateFormat sdf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
			String s = sdf.format(d);
			writer.write(s);
			writer.write(" " + cid + "\n");
            writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/*
	 * Output data to file
	 */
	void inputData(){
		/*
		for(int i = 0; i < vector.size(); i++)
			System.out.println(vector.elementAt(i));
		*/
		try {
			File file = new File(outaddress + vector.elementAt(5));
			FileOutputStream fos = new FileOutputStream(file);
			PrintWriter pw = new PrintWriter(fos);
			for(int i = 0; i < vector.size(); i++)
				pw.write(vector.elementAt(i) + "\n");
			pw.close();
			fos.close();
			addUser(vector.elementAt(5));
			addTime(vector.elementAt(5));
		} catch (IOException e) {
			System.out.println("Get user's data error!");
		}

	}
	/*
	 * Main
	 */
	public static void main(String[] args) {
		MysqlServer mServer = new MysqlServer();
		mServer.loadConfig();
		mServer.loadConfig();
		mServer.getConnect();
		/*
		 * read
		 */
		String sql = "";
		sql = "SELECT * FROM "
				+ args[0] + " WHERE " + args[1] + " = \"" + args[2] + "\"";

		if(args.length == 3){
			mServer.runSQL(sql);
			mServer.closeConnect();
			mServer.inputData();
		}
	}

}
