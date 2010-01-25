from Helpers import *
from Vector2 import *

class Tank(pygame.sprite.Sprite):
    """This is our snake that will move around the screen
    """    
    def __init__(self ):
        pygame.sprite.Sprite.__init__(self)
        self.image,self.rect = load_image('tank.png',-1)
        self.lives = 3
	#test position
	self.pos = Vector2(100,100)

        
    def move_up(self):
	"""
	"""
	self.pos += Vector2(0,-1)

    def move_down(self):
	self.pos += Vector2(0,1)

    def move_left(self):
	"""
	"""
	self.pos += Vector2(-1,0)

    def move_right(self):
	"""
	"""
	self.pos += Vector2(1,0)

    
	

	

	

