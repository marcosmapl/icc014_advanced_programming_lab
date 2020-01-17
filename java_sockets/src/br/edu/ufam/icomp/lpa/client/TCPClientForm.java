package br.edu.ufam.icomp.lpa.client;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

//To run use: java -cp <filename>.jar br.edu.ufam.icomp.lpa.client.TCPClient
public class TCPClientForm extends JFrame {

	private static final long serialVersionUID = 6663587910506907747L;
	private static final String SERVER_HOST = "localhost";
	private static final int SERVER_PORT = 2240;

	private DataInputStream din;
	private DataOutputStream dout;
	private Socket client;

	private static boolean IS_RUNNING = true;

	private JPanel contentPane;
	private JTextArea chatTextArea;
	private JTextField textField;
	private String userName;

	public TCPClientForm(String host, int port) throws UnknownHostException, IOException {
		initialize();
		client = new Socket(host, port);
		din = new DataInputStream(client.getInputStream());
		dout = new DataOutputStream(client.getOutputStream());
		dout.writeUTF(userName + " entrou no chat." + System.lineSeparator());
		new ServerListener().start();
	}

	public static void main(String[] args) throws UnknownHostException, IOException {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TCPClientForm window = new TCPClientForm(SERVER_HOST, SERVER_PORT);
					window.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		userName = null;
		do {
			userName = JOptionPane.showInputDialog(this, "Informe seu nome de usuário: ", "Nome do Usuário",
					JOptionPane.QUESTION_MESSAGE);
		} while ((userName == null) || (userName.isEmpty()));

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Chat Client [" + userName + "]");
		setBounds(100, 100, 800, 600);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);

		JPanel chatPanel = new JPanel();
		chatPanel.setBorder(new LineBorder(new Color(0, 0, 0), 2));
		contentPane.add(chatPanel, BorderLayout.CENTER);
		chatPanel.setLayout(new BoxLayout(chatPanel, BoxLayout.X_AXIS));

		chatTextArea = new JTextArea();
		chatTextArea.setRows(25);
		chatTextArea.setTabSize(400);
		chatTextArea.setEditable(false);

		JScrollPane scroll = new JScrollPane(chatTextArea);
		chatPanel.add(scroll);

		JPanel cmdPanel = new JPanel();
		cmdPanel.setBorder(new LineBorder(new Color(0, 0, 0), 2));
		contentPane.add(cmdPanel, BorderLayout.SOUTH);
		cmdPanel.setLayout(new BoxLayout(cmdPanel, BoxLayout.X_AXIS));

		textField = new JTextField();
		cmdPanel.add(textField);
		textField.setColumns(10);

		JButton btnEnviar = new JButton("Enviar");
		btnEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!textField.getText().isEmpty()) {
					final StringBuilder sb = new StringBuilder();
					if (!textField.getText().equalsIgnoreCase(".quit")) {
						sb.append(userName + " diz: ");
						sb.append(textField.getText());
						sb.append(System.lineSeparator());
						sendMsgToServer(sb.toString());
						chatTextArea.append(sb.toString());
						textField.setText("");
					} else {
						endClient();
					}
				}
			}
		});
		cmdPanel.add(btnEnviar);
		getRootPane().setDefaultButton(btnEnviar);

		JButton btnLimpar = new JButton("Limpar");
		btnLimpar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				chatTextArea.setText("");
			}
		});
		cmdPanel.add(btnLimpar);

		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				if (IS_RUNNING)
					endClient();
				super.windowClosing(e);
				System.out.println("Fechando");
			}
		});
	}

	private void sendMsgToServer(String msg) {
		try {
			dout.writeUTF(msg);
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null, "Falha ao enviar a mensagem!", "Erro", ERROR);
		}
	}

	private void endClient() {
		IS_RUNNING = false;
		try {
			sendMsgToServer(userName + " deixou o chat." + System.lineSeparator());
			sendMsgToServer(".quit" + System.lineSeparator());
			din.close();
			dout.close();
			client.close();
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}

	private void addMessageToChat(String msg) {
		chatTextArea.append(msg);
	}

	class ServerListener extends Thread {
		public void run() {
			while (IS_RUNNING) {
				try {
					final String msg = din.readUTF();
					System.out.println("Client receive new msg from server: " + msg);
					addMessageToChat(msg);
				} catch (IOException e) {
					System.out.println(e.getMessage());
				}
			}
		}
	}

}
