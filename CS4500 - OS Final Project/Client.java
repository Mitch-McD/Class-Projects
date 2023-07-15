package com.example.osproject1;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Client
{
    public static void main(String[] args)  {

        try {
            // this could be changed to an IP name or address other than the localhost
            Socket sock = new Socket("127.0.0.1",6013);

            // write to OutputStream
            PrintWriter pout = new PrintWriter(sock.getOutputStream(), true);

            // Scanner for user input
            Scanner scan = new Scanner(System.in);
            String input = "";

            // InputStream def, reading from Server
            InputStream in = sock.getInputStream();
            BufferedReader bin = new BufferedReader(new InputStreamReader(in));

            while (true) {
                System.out.print("Input: ");
                // get input from console
                input = scan.nextLine();
                // print input to OutputStream
                pout.println(input);
                String line;
                // if done, exit Client
                if (input.equals("Done"))
                    break;
                // if stuff to print, print
                if((line = bin.readLine()) != null)
                    System.out.println(line);

            }
            // close socket
            sock.close();
        }
        catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
