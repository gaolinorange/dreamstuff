import os,sys
import pygame
from pygame.locals import *
"""from Helpers import * """ 
from Tank import *
from Map import *
from Exploration import *


if not pygame.font : print "warning, not font"
if not pygame.mixer: print 'warning, not mixer'

class TankGame(object):
    """The main pyman class- this class handles the main initialization and
    creating of the Game.
    """
    
    def __init__(self,width = 640,height = 480  ):
        """Initialize"""
        """Initial Pygame"""
        pygame.init()
        """set the window size"""
        self.width = width
        self.height = height
        """create the screen"""
        self.screen = pygame.display.set_mode((self.width,self.height))
        pygame.display.set_caption("Tank Battle")
	
    def MainLoop(self):
        self.loadSprites()

	clock = pygame.time.Clock()
	
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()

	    pressed_keys = pygame.key.get_pressed()

	    if pressed_keys[K_UP]:
		self.tank.move_up()
	    elif pressed_keys[K_DOWN]:
		self.tank.move_down()
	    elif pressed_keys[K_RIGHT]:
		self.tank.move_right()
	    elif pressed_keys[K_LEFT]:
		self.tank.move_left()
            elif pressed_keys[K_SPACE]:
                self.exploration.trigger_animate()
                

#draw the background first
	    self.screen.blit(self.map.map_surface,(0,0))
	   
	    self.screen.blit(self.tank.image,(self.tank.pos.x,self.tank.pos.y))
	    

	    
		    
            #self.tank_sprites.draw(self.screen)
#	    self.screen.blit(self.map.map_surface,(0,0))
#	    self.screen.blit(self.tank.image,(0,0))


	    time_passed = clock.tick(50)

# Test exploration 
#	    self.exploration.updateAnimation()
#	    self.screen.blit(self.exploration.image,(0,0),self.exploration.render_area)

#update and render
	    self.exploration.updateAnimation()
	    self.exploration.render()


	    pygame.display.update()
            
    def loadSprites(self):
        self.tank = Tank()
	self.exploration = Exploration(self.screen,(100,100))
	self.map = Map(self.height,self.height,32,32)
        
	"""currently it is tank_sprites,later, you should decouple these"""
	#self.tank_sprites = pygame.sprite.RenderPlain((self.tank))
        

if __name__ == '__main__':
    tankGame = TankGame()
    tankGame.MainLoop()
    

        
        
        
        
	
