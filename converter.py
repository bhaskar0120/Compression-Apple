
def simple():
    pass

from sys import argv
compressionType = {
        'simple' : simple
        }

types = [
        (1,'raw','Raw; with no compression')
        ]

def err_exit(errno):
    print("USAGE: ./python3 converter.py [Type] \n\nAvailable Types")
    for i,t,desc in types:
        print('{}. {} - {}.'.format(i,t,desc))
    exit(errno)
        
if __name__ == "__main__":
    if len(argv) != 2:
        err_exit(1)
    if argv[1] not in compressionType:
        err_exit(1)
    compressionType[argv[1]]()

