package cmysqlclient;
import java.io.*;
import java.net.*;

public class Client {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Connection c = new Connection();

//		String s = "58.198.176.153";
		String s = "10.11.1.192";
//		int port = 34568;
		int port = 8001;
		c.init(s, port);
		System.out.println(s);

		// get sql statement from system in
		String sql = "";
		try {
			BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));
			sql = sin.readLine();
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		
		c.send_sql(sql);


		String result_set = c.receive_claims_result();
//		String result_set = c.receive_result_set();

		System.out.println("receive from server: ");
		System.out.println(result_set);
		c.close();
	}

}

class Connection {
	Socket socket;
	InputStream in;
	OutputStream out;
	public Connection() {

	}
	public int init(String s, int port) {
		int ret = 0;
		try {
			socket = new Socket(s, port);

//			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));	//由Socket对象得到输入流，并构造相应的BufferedReader对象
			in = socket.getInputStream();
//			out = new PrintWriter(socket.getOutputStream(), true);	//由Socket对象得到输出流，并构造PrintWriter对象
			out = socket.getOutputStream();

		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return ret;
	}

	public int send_sql(String s) {
		int ret = 1;
		if (s == null) {
			return -1;
		}
		else {
			try {
				out.write(s.getBytes());
			} catch (IOException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
		}

		System.out.println("send to server:"+s);
		return ret;
	}

	public String receive_claims_result() {
		String ret = null;
		int status = -1;
		int length = -1;
		int read_count = 0;
		if ((status = read_unsigned_int()) == -1) {
			System.out.println("read status error");
			return ret;
		}
		System.out.println("status is: "+ status);
		if ((length = read_unsigned_int()) == -1) {
			System.out.println("read length error");
			return ret;
		}
		System.out.println("length is: "+ length);
		byte content[] = new byte[length];
		try {
			read_count = in.read(content);
			ret = new String(content);
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return ret;
	}

	public String receive_result_set(){
		byte[] len=new byte[1024];
		try {
			in.read(len, 0, 1024);
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}		
		return new String(len);
	}

	public void close() {
		try {
			socket.close();
			in.close();
			out.close();
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}

	/**
	 *  read unsigned int from socket input stream.
	 *  return the value read, or -1 if failed
	 **/
	int read_unsigned_int() {
		byte[] buf = new byte[4];
		int value = 0;
		int read_count = 0;
		try {
			if ((read_count = in.read(buf)) != -1) {
				for (int i = 3; i >= 0; --i) {
					value <<= 8;
					value += buf[i] & 0xFF;
				}
//				ByteArrayInputStream bintput = new ByteArrayInputStream(buf);
//				DataInputStream dintput = new DataInputStream(bintput);
//				value = dintput.readInt();	//网络字节序是大端字节序，所以读取是按大端字节序来读取，而实际c++端是按小端序来存放，出错
				System.out.println(value);
			}
			else {
				value = -1;
			}
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return value;
	}
}
