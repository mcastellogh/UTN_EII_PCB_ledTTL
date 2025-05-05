import random

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


MAX_FIFO=5
ringdata=[]
global elems, pread, pwrite


def queue_init():
    global elems, pread, pwrite, index
    print("Init data")
    elems = 0
    pread = 0
    pwrite = 0
    index=0
    for i in range(0,MAX_FIFO):
        ringdata.append(0)
    printRing()

# Función que devuelve verdadero si la cola está vacía:
def is_empty():
    global elems, pread, pwrite
    return (elems == 0)

# Función que devuelve verdadero si la cola está llena:
def is_full():
    global elems, pread, pwrite
    return (elems == MAX_FIFO)

# Muestra el primer indice disponible
def next_idx():
    global elems, pread, pwrite
    return pread

# Calcula cantidad de datos disponibles
def data_enq():
  global elems, pread, pwrite
  if (pwrite<pread):
    return MAX_FIFO-abs(pwrite-pread)
  else:
    return pwrite-pread

def printRing():
    print("Ringdata:",end=' ')
    for i in range(MAX_FIFO):
        if i==pread:
            print(bcolors.OKGREEN+bcolors.BOLD+str(i)+"->"+str(ringdata[i])+"   "+bcolors.ENDC,)
            print(end='')
        if i==pread:
            print(bcolors.FAIL+bcolors.BOLD+str(i)+"->"+str(ringdata[i])+"   "+bcolors.ENDC,)
            print(end='')
        else:
            print(i,"->",ringdata[i],"   ",end=' ')
    print()


# Encolado
def enqueue():
    global elems, pread, pwrite, index
    elems=elems+1
    index=index+1
    ringdata[pwrite]=index#random.random()
    if(data_enq()==MAX_FIFO-1):
      if (pread==MAX_FIFO-1):
        pread=0
      else:
        pread=pread+1
    pwrite=pwrite+1
    if (pwrite == MAX_FIFO):
      pwrite = 0

# Desencolado
def dequeue():
    global elems, pread, pwrite
    prox_idx_dato=0
    elems=elems-1
    prox_idx_dato=pread
    pread=pread+1
    if (pread == MAX_FIFO):
        pread = 0
    return prox_idx_dato

# Reencolado
def requeue():
    global elems, pread, pwrite
    prev_idx_dato=0
    elems=elems+1
    prev_idx_dato=pread

    pread=pread-1
    if (pread == MAX_FIFO):
      pread = 0

    return prev_idx_dato





queue_init()
#for i in range(0,MAX_FIFO):
    #print(ringdata[i])

for i in range(0,25):
    enqueue()
    printRing()
enqueue()
printRing()
enqueue()
printRing()
#dequeue()
#printRing()
enqueue()
printRing()
enqueue()
printRing()
enqueue()
printRing()
enqueue()
printRing()
print("disp pread pwrite")
print(elems,data_enq(),pread,pwrite)
#dequeue()
#print(data_enq(),pread,pwrite)

