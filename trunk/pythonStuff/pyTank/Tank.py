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
	self.element_width = self.element_height = 32
	self.render_area = ((0,0),(32,32))
	#the flag to swap the tank rendering in the same direction
	self.render_swap_flag = True

        
    def move_up(self):
	"""
	"""
	self.pos += Vector2(0,-1)

	if self.render_swap_flag == True:
	    self.render_area = ((0,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True
	
    def move_down(self):
	self.pos += Vector2(0,1)
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*6,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*7,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True
	

    def move_left(self):
	"""
	"""
	self.pos += Vector2(-1,0)
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*2,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*3,0),(self.element_width,self.element_height))
	    

    def move_right(self):
	"""
	"""
	self.pos += Vector2(1,0)
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*4,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*5,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True

    def render(self):
        self.screen.blit(self.image,(self.pos.x,self.pos.y),self.render_area)
        
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
    
	

	

	

