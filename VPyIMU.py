from visual import *
import time
import math as m

"""
ball = sphere(pos=(-5,0,0), radius=0.9, color=color.cyan)
#wallR = box(pos=(6,0,0), size=(0.2,12,12), color=color.green)

ball.velocity = vector(25,0,0)
deltat = 0.005
t = 0


for _ in range(50):
	ball.pos = ball.pos + ball.velocity*deltat
	time.sleep(0.01)
"""

# index, middle, ring, pinky
# distal = 1 , medial, proximal, metacarpal (not used)
phalanx_ratios_index = [1,1.4,2.5,4.3]
phalanx_ratios_mid = [1,1.5,2.6,3.7]
phalanx_ratios_ring = [1,1.5,2.4,3.4]
phalanx_ratios_pinky = [1,1.1,2.1,3.4]

#### based on IMU angle, determine finger position... 
###   assume straight knuckle atm

# length = distal length
# Only working in 2D ....dw about z 
def makeFinger (spawnPos,ratio, length, angle):

	x = spawnPos[0]
	y = spawnPos[1]
	z = spawnPos[2]
	angle = m.radians(angle)
	prox = cylinder(pos = (x,y,z), axis = (length*ratio[2],0,0), radius = 1.2)

	xStart = x + length*ratio[2]
	yStart = y
	axisX = m.cos(angle/2.0)*length*ratio[1]
	axisY = m.sin(angle/2.0)*length*ratio[1]
	med = cylinder(pos = (xStart, yStart,z), \
		axis = (axisX, axisY,0), \
		radius = 1.1)

	xStart = x + length*ratio[2] + m.cos(angle/2.0)*length*ratio[1]
	yStart = y + m.sin(angle/2.0)*length*ratio[1]
	axisX = m.cos(angle)*length*ratio[0]
	axisY = m.sin(angle)*length*ratio[0]
	dist = cylinder(pos = (xStart,yStart,z), \
		axis = (axisX, axisY, 0),\
		 radius = 1) 
	return prox,med,dist

initPos = [2,1,0]
degree = 25

### Move finger model 
for degree in range(0,180,5):
	prox, med, dist = makeFinger(initPos, phalanx_ratios_index, 5, degree)
	time.sleep(0.025)
	dist.visible = False
	med.visible = False
	prox.visible = False
	del dist,med,prox


exit()

"""
RATIOS: 

proximal = closer to palm

https://scielo.conicyt.cl/pdf/ijmorphol/v28n3/art15.pdf

"""