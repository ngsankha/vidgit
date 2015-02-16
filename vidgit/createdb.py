import sqlite3

def createdb(filename):
  conn = sqlite3.connect(filename)
  c = conn.cursor()
  c.execute('''CREATE TABLE history
               (node TEXT PRIMARY KEY,
                parents TEXT,
                edge TEXT)''')

  c.execute('''CREATE TABLE edges
               (edge TEXT PRIMARY KEY,
                op_id INT,
                op_name TEXT,
                params TEXT)''')
  conn.commit()

createdb('test.db')
