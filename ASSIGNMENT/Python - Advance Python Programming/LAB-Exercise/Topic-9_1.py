import sqlite3

con = sqlite3.connect("student.db")
cur = con.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS student(id INTEGER, name TEXT)")
cur.execute("INSERT INTO student VALUES(101, 'Harshad')")
con.commit()

cur.execute("SELECT * FROM student")
print(cur.fetchall())

con.close()