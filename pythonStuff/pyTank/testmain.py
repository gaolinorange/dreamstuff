import pygame
from pygame.locals import *

from EmptyMap import *
from EnemyTank import *

class TankBattleGame(object):
    """
    """
    
    def __init__(self):
        """
        """
	pygame.init()
	self.screen = pygame.display.set_mode((640,480))
	
	self.tank_group = pygame.sprite.Group()
	self.tank0 = EnemyTank()
	self.tank_group.add(self.tank0)
	self.map = EmptyMap(self.screen,640,480)
	
    def run(self):
	clock = pygame.time.Clock()
	while True:
	    for event in pygame.event.get():
		if event.type == pygame.QUIT:
		    sys.exit()

	    self.map.render()
	    #self.tank_group.draw(self.screen)
	    self.tank_group.draw(self.screen)
	    pygame.display.update()

if __name__ == '__main__':
    tankGame = TankBattleGame()
    tankGame.run()
    
        
        
