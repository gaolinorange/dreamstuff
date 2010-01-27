from Helpers import *
from Vector2 import *


class Tank(pygame.sprite.Sprite):
    """This is our snake that will move around the screen
    """    
    def __init__(self,screen ):
        pygame.sprite.Sprite.__init__(self)
        self.image,self.rect = load_image('tank.png',-1)
        self.lives = 3
	#test position
	self.pos = Vector2(100,100)
        self.screen = screen

        
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

    def render(self):
        self.screen.blit(self.image,(self.pos.x,self.pos.y))
        

    def update_movement(self,pressed_keys):
        if pressed_keys[K_UP]:
            self.move_up()
        elif pressed_keys[K_DOWN]:
            self.move_down()
        elif pressed_keys[K_RIGHT]:
            self.move_right()
        elif pressed_keys[K_LEFT]:
            self.move_left()
        elif pressed_keys[K_SPACE]:
            self.fire()
        
    def fire(self):
        print "fire"
    
	

	

	

