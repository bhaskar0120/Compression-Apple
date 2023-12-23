
def raw(file,size=(40,30)):
    from cv2 import VideoCapture, imshow, waitKey, resize
    video = VideoCapture(file)
    cols, rows = size
    success, frame = video.read()
    with open('out.bin','wb') as f:
        f.write(rows.to_bytes(4,'little')+cols.to_bytes(4,'little'))
        while success:
            frame = resize(frame,size);
            f.write(frame[:,:,0].tobytes())
            success, frame = video.read()

    



compressionType = {
        'raw' : raw
        }

types = [
        (1,'raw','Raw; with no compression')
        ]

def err_exit(errno):
    print("USAGE: ./python3 converter.py [Type] [Video File] \n\nAvailable Types")
    for i,t,desc in types:
        print('{}. {} - {}.'.format(i,t,desc))
    exit(errno)

if __name__ == "__main__":
    from sys import argv
    if len(argv) != 3:
        err_exit(1)
    if argv[1] not in compressionType:
        err_exit(1)
    compressionType[argv[1]](argv[2])

