import sqlite3
import ast

class State:

  def __init__(self, conn, state, parents, operation_id):
    self.conn = conn
    self.state = state
    self.parents = parents
    self.operation_id = operation_id

  def hash(self):
    return self.state

  def get_parents(self):
    print self.parents

  def operations(self):
    c = self.conn.cursor()
    res = c.execute('SELECT op_id, op_name, params FROM edges WHERE edge=?', (self.operation_id,))
    for row in res:
      print row

class HistoryTree:

  def __init__(self, filename):
    self.conn = sqlite3.connect(filename)

  def get_state(self, state):
    c = self.conn.cursor()
    res = c.execute('SELECT * FROM history WHERE node=?', (state,)).fetchone()
    parents = ast.literal_eval(res[1])
    s = State(self.conn, res[0], parents, res[2])
    return s

############
# TEST
############
h = HistoryTree('test.db')
s = h.get_state('abcde')
print s.hash()
print s.get_parents()
s.operations()

