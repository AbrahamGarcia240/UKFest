import socket
import sys


class Sender:
    filename = ""
    sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    UDP_IP = "127.0.0.1"
    UDP_PORT = 7200
    def __init__(self,filename):
        self.filename = filename

    def sendN(self,n):
        nn = chr(int(n)).encode("utf-8")
        self.sock.sendto(nn,(self.UDP_IP,self.UDP_PORT))
        data = self.sock.recvfrom(1024)
        print(data)

    def sendFile(self):
        f = open("media/Archivos/"+self.filename,'rb')        
        data = f.read(1024)
        while (data):
            if(self.sock.sendto(data,(self.UDP_IP,self.UDP_PORT))):
                print ("sending ...")
                data = f.read(1024)
                print(data)
    

    def receive(self):
        f = open("salida.txt","wb")
        data,addr = self.sock.recvfrom(1024)
        try:
            while(data):
                f.write(data)
                self.sock.settimeout(2)
                data,addr = self.sock.recvfrom(1024)
        except timeout:
            f.close()

    def closeCone(self):
        self.sock.close()