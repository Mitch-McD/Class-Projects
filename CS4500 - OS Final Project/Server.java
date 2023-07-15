package com.example.osproject1;

import java.net.*;
import java.io.*;

public class Server
{
    public static void main(String[] args)  {
        try {
            // open socket at port 6013 and IP 127.0.0.1 (localhost)
            ServerSocket sock = new ServerSocket(6013);
            System.out.println("Waiting for connection...");

            // now listen for connections
            while (true) {
                Socket client = sock.accept();
                // we have a connection
                System.out.println("Connected!");

                // InputStream/Buffer definition to read from Client
                InputStream in = client.getInputStream();
                BufferedReader bin = new BufferedReader(new InputStreamReader(in));
                String line = "";

                while(true) {
                    // If there's something to print, print it
                    if ((line = bin.readLine()) != null)
                        System.out.println("Server: " + line);

                    // OutputStream to write back to client
                    PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

                    // if Done, exit
                    if (line.equals("Done"))
                        break;
                    // write data to socket
                    pout.println("Client Echo: " + line);
                }
                client.close();
                System.out.println("Disconnected.\nWaiting for connection...");
                break;

            }
        }
        catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
