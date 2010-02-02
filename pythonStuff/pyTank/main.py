import os,sys
import pygame
from pygame.locals import *
"""from Helpers import * """ 
from Tank import *
from Map import *
from Exploration import *
from EnemyTank import *

from EmptyMap import *



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

#test trigger exploration
	    if pressed_keys[K_x]:
		self.exploration.trigger_animate()

	    # for testing convinence
	    if pressed_keys[K_ESCAPE]:
		sys.exit()
	    if pressed_keys[K_q]:
		sys.exit()

	    self.empty_map.render()	    
		

#draw the background first
#	    self.screen.blit(self.map.map_surface,(0,0))



            self.tank.update_movement(pressed_keys)
	    self.tank.render()
	    
	    time_passed = clock.tick(50)

#update and render
	    self.exploration.updateAnimation()
	    self.exploration.render()


	    self.enemy_group.update()
	    for enemy in self.enemy_group:
		enemy.render()
	    
#	    self.enemy_tank0.render()
#	    self.enemy_tank1.render()

#	    self.enemy_tank_group.update()
#	    self.enemy_tank_group.draw(self.screen)


	    pygame.display.update()
            
    def loadSprites(self):
        self.tank = Tank(self.screen)
	self.exploration = Exploration(self.screen,(100,100))
	self.map = Map(self.height,self.height,32,32)

	enemy_tank0 = EnemyTank(self.screen)
	enemy_tank1 = EnemyTank(self.screen)

	self.enemy_group = pygame.sprite.Group()
	self.enemy_group.add(enemy_tank0,enemy_tank1)

	
	    
	self.empty_map = EmptyMap(self.screen,self.width,self.height)
	
	
	"""currently it is tank_sprites,later, you should decouple these"""
	#self.tank_sprites = pygame.sprite.RenderPlain((self.tank))
        

if __name__ == '__main__':
    tankGame = TankGame()
    tankGame.MainLoop()
    

        
        
        
        
	
