from tkinter import *
from tkinter import filedialog
from time import sleep

PIXEL_SIZE = 20
SCREEN_WIDTH = 32
SCREEN_HEIGHT = 24

def zeros(w, h):
	mat = []
	for y in range(h):
		mat.append([])
		for x in range(w):
			mat[y].append(0)
	return mat

frameIndex = 0
currentMat = zeros(38, 24)

Mats = []
Mats.append(currentMat)

win = Tk()
win.title("AnimationCreator")
win.resizable(width=False, height=False)

def can_onLMove(event):
	global currentMat, Mats
	caseX = int(event.x/PIXEL_SIZE)
	caseY = int(event.y/PIXEL_SIZE)
	currentMat[caseY][caseX] = 1
	clean()
	try:
		draw(Mats[frameIndex-1], "#F88")
	except:
		pass
	draw(currentMat)
def can_onRMove(event):
	global currentMat
	caseX = int(event.x/PIXEL_SIZE)
	caseY = int(event.y/PIXEL_SIZE)
	currentMat[caseY][caseX] = 0
	clean()
	try:
		draw(Mats[frameIndex-1], "#F88")
	except:
		pass
	draw(currentMat)
can = Canvas(win, width=PIXEL_SIZE*SCREEN_WIDTH-3, 
	height=PIXEL_SIZE*SCREEN_HEIGHT-3, borderwidth=1, relief="solid")
can.pack(side="left")
can.bind("<Button-1>", can_onLMove)
can.bind("<Button-3>", can_onRMove)
can.bind("<B1-Motion>", can_onLMove)
can.bind("<B3-Motion>", can_onRMove)

frame_tools = Frame(win)
frame_tools.pack(side="left")

def txb_frameIndex_onkey(event):
	global frameIndex, Mats, currentMat, txb_frames
	try:
		frameIndex = int(txb_frameIndex.get())
		txb_frameIndex.config({"background" : "orange"})
		txb_frameIndex.update()
		while len(Mats) < frameIndex+1:
			Mats.append(zeros(38, 24))
		currentMat = Mats[frameIndex]
		clean()
		try:
			draw(Mats[frameIndex-1], "#F88")
		except:
			pass
		draw(currentMat)
		txb_frameIndex.config({"background": "white"})
		txb_frames.delete(0, END)
		txb_frames.insert(0, str(len(Mats)-1))
	except:
		txb_frameIndex.config({"background": "red"})
txb_frameIndex = Entry(frame_tools, width=5)
txb_frameIndex.grid(row=0, column=1)
txb_frameIndex.insert(0, "0")
txb_frameIndex.bind("<Key>", txb_frameIndex_onkey)

def btn_prevFrame_onclick(event):
	global frameIndex, currentMat, Mats
	if(frameIndex-1 >= 0):
		frameIndex -= 1
	txb_frameIndex.delete(0, END)
	txb_frameIndex.insert(0, frameIndex)
	currentMat = Mats[frameIndex]
	clean()
	try:
		draw(Mats[frameIndex-1], "#F88")
	except:
		pass
	draw(currentMat)
btn_prevFrame = Button(frame_tools, text="<")
btn_prevFrame.grid(row=0, column=0, padx=5)
btn_prevFrame.bind("<Button-1>", btn_prevFrame_onclick)

def win_leftKey(event):
	btn_prevFrame.event_generate("<Button-1>")
win.bind("<Left>", win_leftKey)

def btn_nextFrame_onclick(event):
	global frameIndex, Mats, currentMat
	frameIndex += 1
	if(frameIndex > len(Mats)-1):
		Mats.append(zeros(38, 24))
		frameIndex = len(Mats)-1
		txb_frames.delete(0, END)
		txb_frames.insert(0, str(len(Mats)-1))
	txb_frameIndex.delete(0, END)
	txb_frameIndex.insert(0, frameIndex)
	currentMat = Mats[frameIndex]
	clean()
	try:
		draw(Mats[frameIndex-1], "#F88")
	except:
		pass
	draw(currentMat)
btn_nextFrame = Button(frame_tools, text=">")
btn_nextFrame.grid(row=0, column=2, padx=5)
btn_nextFrame.bind("<Button-1>", btn_nextFrame_onclick)

def win_rightKey(event):
	btn_nextFrame.event_generate("<Button-1>")
win.bind("<Right>", win_rightKey)

lbl_frames = Label(frame_tools, text="Frames:")
lbl_frames.grid(row=1, column=0)
txb_frames = Entry(frame_tools, width=5)
txb_frames.grid(row=1, column=1)

def btn_export_click(event):
	filename = filedialog.asksaveasfilename(defaultextension="*.*", initialdir = "/", filetypes = (("Txt files","*.txt"),("all files","*.*")))
	file = open(filename, "w")
	for mat in Mats:
		file.write("myScreen.clear();");
		for y in range(len(mat)):
			for x in range(len(mat[0])):
				if mat[y][x]:
					file.write("myScreen.setLed(" + str(x) + "," + str(y) + ", true);")
	file.close()
btn_export = Button(frame_tools, text="export")
btn_export.grid(row=2, column=1, pady=5)
btn_export.bind("<Button-1>", btn_export_click)

def btn_play_click(event):
	clean()
	draw(currentMat)
	for i in range(frameIndex, len(Mats)-1):
		btn_nextFrame.event_generate("<Button-1>")
		clean()
		draw(currentMat)
		can.update()
		sleep(0.01)
btn_play = Button(frame_tools, text="play")
btn_play.grid(row=3, column=1, pady=5)
btn_play.bind("<Button-1>", btn_play_click)

def clean():
	can.delete(ALL)
	for y in range(SCREEN_HEIGHT*PIXEL_SIZE):
		can.create_line(0, y*PIXEL_SIZE, SCREEN_WIDTH*PIXEL_SIZE, y*PIXEL_SIZE, fill="black")
	for x in range(SCREEN_WIDTH*PIXEL_SIZE):
		can.create_line(x*PIXEL_SIZE, 0, x*PIXEL_SIZE, SCREEN_HEIGHT*PIXEL_SIZE, fill="black")

def draw(mat, col="red"):
	for y in range(len(mat)):
		for x in range(len(mat[0])):
			if mat[y][x]:
				can.create_rectangle(x*PIXEL_SIZE, y*PIXEL_SIZE, (x+1)*PIXEL_SIZE, (y+1)*PIXEL_SIZE, fill=col)


clean()
draw(currentMat)

win.mainloop()