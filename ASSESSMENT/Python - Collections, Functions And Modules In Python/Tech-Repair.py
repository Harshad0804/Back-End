import sqlite3, re, tkinter as tk
from tkinter import messagebox

conn = sqlite3.connect('repairmate.db')
c = conn.cursor()
c.execute('''CREATE TABLE IF NOT EXISTS customers(id INTEGER PRIMARY KEY, name TEXT, phone TEXT)''')
c.execute('''CREATE TABLE IF NOT EXISTS devices(id INTEGER PRIMARY KEY, customer_id INT, model TEXT, issue TEXT, status TEXT)''')
c.execute('''CREATE TABLE IF NOT EXISTS bills(id INTEGER PRIMARY KEY, device_id INT, parts REAL, service REAL, tax REAL, total REAL)''')
conn.commit()

class Customer:
    def __init__(self, name, phone):
        self.name, self.phone = name, phone
    def save(self):
        c.execute("INSERT INTO customers(name, phone) VALUES(?,?)",(self.name,self.phone))
        conn.commit()

class Device:
    def __init__(self, cid, model, issue):
        self.cid, self.model, self.issue = cid, model, issue
    def save(self):
        c.execute("INSERT INTO devices(customer_id, model, issue, status) VALUES(?,?,?,?)",(self.cid,self.model,self.issue,'Pending'))
        conn.commit()

class Billing:
    def __init__(self, did, parts, service):
        self.did, self.parts, self.service = did, parts, service
    def calc(self):
        try:
            tax = 0.18*(self.parts+self.service)
            total = self.parts+self.service+tax
            c.execute("INSERT INTO bills(device_id, parts, service, tax, total) VALUES(?,?,?,?,?)",
                      (self.did,self.parts,self.service,tax,total))
            conn.commit()
            return total
        except Exception as e:
            return f"Error: {e}"

def search_device(pattern):
    rows = c.execute("SELECT * FROM devices").fetchall()
    return [r for r in rows if re.search(pattern, str(r), re.IGNORECASE)]

root = tk.Tk()
root.title("RepairMate")
tk.Label(root, text="Customer Name").grid(row=0, column=0)
tk.Label(root, text="Phone").grid(row=1, column=0)
name=tk.Entry(root); phone=tk.Entry(root)
name.grid(row=0,column=1); phone.grid(row=1,column=1)

def add_customer():
    try:
        Customer(name.get(), phone.get()).save()
        messagebox.showinfo("Success","Customer added!")
    except Exception as e:
        messagebox.showerror("Error", str(e))

tk.Button(root,text="Add Customer",command=add_customer).grid(row=2,column=0,columnspan=2)
root.mainloop()
