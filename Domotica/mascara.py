import serial
import time
from tkinter import*
color="#00878F"

arduino=serial.Serial('COM3',9600)
time.sleep(2)

def foco1():
	arduino.write('a'.encode())

def foco2():
	arduino.write('s'.encode())

def foco3():
	arduino.write('d'.encode())		
	

def cerrar():
	arduino.close()
	ventana.destroy()



ventana=Tk()
Label(ventana,text="PRO-PYTHON",bg=color,fg=("#FFFFFF"),font=("Times New Roman",12)).place(x=150,y=10)
ventana.configure(background=color)
ventana.title("Casa Domotica con Arduino")
ox,oy=ventana.winfo_screenwidth()/2,ventana.winfo_screenheight()/2
ventana.geometry("400x200+%d+%d"% (ox-200,oy-100))
ventana.wm_deiconify()
ventana.iconbitmap("jk.ico")
#ventana.geometry('350x200')
#label=Label(ventana,text="")
#label.grid(row=1,column=1)
#35A8CC
b1=Button(ventana,text="Prende/Apaga FOCO1",font=("Comic Sans MS",10),command=foco1,bg='#C9DB2C')
b1.place(x=140,y=40)
b2=Button(ventana,text="Prende/Apaga FOCO2",font=("Comic Sans MS",10),command=foco2,bg='#C9DB2C')
b2.place(x=140,y=80)
b3=Button(ventana,text="Prende/Apaga FOCO3",font=("Comic Sans MS",10),command=foco3,bg='#C9DB2C')
b3.place(x=140,y=120)

#b1=Button(ventana,text="Prende/Apaga led",command=led)
#b1.grid(row=0,column=0)
#b2=Button(ventana,text="Actualizar valor",command=potenciometro)
#b2.grid(row=1,column=0)
#b3=Button(ventana,text="Cerrar",command=cerrar)
#b3.grid(row=2,column=0)
b5=Button(ventana,text="Cerrar",font=("Comic Sans MS",10),command=cerrar,bg='#FAED1F')
b5.place(x=175,y=160)
ventana.mainloop()