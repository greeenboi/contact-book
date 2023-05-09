import tkinter
import time
import os
import sys
import customtkinter
from tkinter.ttk import *
import tkinter.messagebox
from PIL import Image

customtkinter.set_appearance_mode("light")  
customtkinter.set_default_color_theme("green")

class App(customtkinter.CTk):
    
    def __init__(self):
        super().__init__()
        self.title("AddressBook")
        self.geometry(f"{1100}x{600}")
        
        self.grid_columnconfigure(1, weight=1)
        self.grid_columnconfigure((2, 3), weight=0)
        self.grid_rowconfigure((0, 1, 2), weight=1)
        
        self.logo_image=customtkinter.CTkImage(light_image=Image.open("./media/phone-book.png"),size=(30,30))
        self.search_image=customtkinter.CTkImage(light_image=Image.open("./media/magnifying-glass.png"),size=(20,20))
        
        self.navigation_frame = customtkinter.CTkFrame(self, corner_radius=0,fg_color=("gray75","gray25"))
        self.navigation_frame.grid(row=0, column=0, rowspan=4, sticky="nsew")
        self.navigation_frame.grid_rowconfigure(4, weight=1)
        
        self.navigation_frame_label = customtkinter.CTkLabel(self.navigation_frame, text="  Address Book", image=self.logo_image,
                                                             compound="left", font=customtkinter.CTkFont(size=15, weight="bold"))
        self.navigation_frame_label.grid(row=0, column=0, padx=(20,20), pady=20)
        
        self.appearance_mode_var = customtkinter.StringVar(value="Light")        
        self.appearance_mode_menu = customtkinter.CTkOptionMenu(self.navigation_frame, values=["Light", "Dark", "System"],command=self.change_appearance_mode_event, variable=self.appearance_mode_var)
        self.appearance_mode_menu.grid(row=4, column=0, padx=20, pady=20, sticky="s")
        
        #home frame
        self.home_frame = customtkinter.CTkFrame(self, corner_radius=0, fg_color="transparent")
        self.home_frame.grid_columnconfigure(0, weight=1)       
        
        self.text_label=customtkinter.CTkLabel(self, width=120,height=30,text="hiiii",justify="left",fg_color=("gray75","gray25") ,text_color=("#000000","#CBE4DE"),corner_radius=8)
        self.text_label.grid(row=0, column=1, padx=(20,20),pady=(10,10),sticky="nsew")
       
        
        self.send_button = customtkinter.CTkButton(master=self, fg_color="transparent",command=self.access_text,text="", image=self.search_image ,border_width=2, width=10,text_color=("gray10", "#DCE4EE"))
        self.send_button.grid(row=3, column=1,columnspan=3 , padx=(10, 10), pady=(10, 20), sticky="nsew")
        
               
        
    def change_appearance_mode_event(self, new_appearance_mode):
        customtkinter.set_appearance_mode(new_appearance_mode)
        
    def access_text(self):
        file=open("./cpp/cmake-build-debug/number.txt","r")
        text=file.read()
        self.text_label.configure(text=text)
        file.close()
    



if __name__ == "__main__":
    app = App()    
    
    app.mainloop()