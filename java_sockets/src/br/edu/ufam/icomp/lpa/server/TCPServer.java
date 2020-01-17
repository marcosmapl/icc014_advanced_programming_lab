package br.edu.ufam.icomp.lpa.server;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

//To run use: java -cp <filename>.jar br.edu.ufam.icomp.lpa.server.TCPServer
public class TCPServer {

	private static ArrayList<Socket> clients;
	private static final int SERVER_PORT = 2240;
	private static boolean IS_RUNNING = true;

	@SuppressWarnings("resource")
	public static void main(String argv[]) throws Exception {
		clients = new ArrayList<Socket>();

		// server end condition thread
		(new Thread(new Runnable() {
			public void run() {
				String cmd = null;
				do {
					final Scanner sc = new Scanner(System.in);
					cmd = sc.nextLine();
				} while ((cmd == null) || (!cmd.equalsIgnoreCase(".quit")));
				IS_RUNNING = false;
			}
		})).start();

		try {
			// Instancia o ServerSocket ouvindo a porta 12345
			System.out.println("Server was started listenning port: " + SERVER_PORT);
			final ServerSocket server = new ServerSocket(SERVER_PORT);
			while (IS_RUNNING) {
				final Socket client = server.accept();
				System.out.println("Cliente conectado: " + client.getInetAddress().getHostAddress());
				clients.add(client);
				// server end condition thread
				(new Thread(new Runnable() {
					public void run() {
						try {
							final DataInputStream din = new DataInputStream(client.getInputStream());
							while (IS_RUNNING) {
								String msg = din.readUTF();
								if (msg.startsWith(".quit")) {
									clients.remove(client);
									client.close();
									break;
								} else
									sendMsgToAllClients(client, msg);
							}
						} catch (IOException e) {
							System.out.println(e.getMessage());
						}
					}
				})).start();

			}
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

	private static synchronized void sendMsgToAllClients(Socket client, String msg) throws IOException {
		for (Socket socket : clients) {
			if (socket != client) {
				final DataOutputStream dout = new DataOutputStream(socket.getOutputStream());
				dout.writeUTF(msg);
			}
		}
	}
}
