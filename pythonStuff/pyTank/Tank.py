from Helpers import *
from Vector2 import *
from Settings import *


class Tank(pygame.sprite.Sprite):
    """This is our snake that will move around the screen
    """    
    def __init__(self,screen ):
        pygame.sprite.Sprite.__init__(self)
        self.image,self.rect = load_image('tank.png',-1)
	self.shoot_sound = load_sound('shoot.wav')
        self.lives = 3
	#test position
	self.pos = Vector2(100,100)
        self.screen = screen
	self.element_width = self.element_height = 32
	self.render_area = ((0,0),(32,32))
	#the flag to swap the tank rendering in the same direction
	self.render_swap_flag = True
        self.direction = Vector2(1,0)
        self.speed = 2

        
    def move_up(self):
	"""
	"""
        self.direction = Vector2(0,-1)
	self.pos += self.direction * self.speed
	if self.pos.y <= 0:
	    self.pos.y = 0

	#update rect for collision detection
	self.rect = ((self.pos.x,self.pos.y),(self.pos.x+self.element_width,self.pos.y+self.element_height))

	if self.render_swap_flag == True:
	    self.render_area = ((0,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True
	
    def move_down(self):
        self.direction = Vector2(0,1)
	self.pos += self.direction * self.speed
	if self.pos.y >= MAP_HEIGHT-self.element_height:
	    self.pos.y = MAP_HEIGHT-self.element_height
	
	#update rect for collision detection
	self.rect = (self.pos.x,self.pos.y,self.pos.x+self.element_width,self.pos.y+self.element_height)
	
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*6,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*7,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True
	

    def move_left(self):
	"""
	"""
        self.direction = Vector2(-1,0)
	self.pos += self.direction * self.speed
	if self.pos.x <= 0:
	    self.pos.x = 0
	    
	#update rect for collision detection
	self.rect = (self.pos.x,self.pos.y,self.pos.x+self.element_width,self.pos.y+self.element_height)
	
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*2,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*3,0),(self.element_width,self.element_height))
	    

    def move_right(self):
	"""
	"""
        self.direction = Vector2(1,0)
	self.pos += self.direction * self.speed
	if self.pos.x >= MAP_WIDTH - self.element_width:
	    self.pos.x = MAP_WIDTH - self.element_width
	    
	#update rect for collision detection
	self.rect = (self.pos.x,self.pos.y,self.pos.x+self.element_width,self.pos.y+self.element_height)
	
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*4,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*5,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True

    def stand_still(self):
	pass

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

        #fire when press SPACE,sepearate from movement
        if pressed_keys[K_SPACE]:
            self.fire()
        
    def fire(self):
        print "fire"
	self.shoot_sound.play()
	
    
	

	

	

