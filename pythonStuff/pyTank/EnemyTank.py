from Helpers import *
from Vector2 import *
from Settings import *
import random


class EnemyTank(pygame.sprite.Sprite):

    def __init__(self,screen):
	#be sure to call the base initializer before adding to Group
	pygame.sprite.Sprite.__init__(self)
	self.screen = screen
        self.image,self.rect = load_image('enemytank.png',-1)

        self.pos = Vector2(100,100)
        self.direction = Vector2(1,0)
        self.speed = 1
	self.move_direction = 0
	self.element_width = 32
	self.element_height = 32
	self.render_area = ((0,0),(self.element_width,self.element_height))
	self.render_swap_flag = True

    def move_up(self):
        self.direction = Vector2(0,-1)
        self.pos += self.direction * self.speed
	if self.render_swap_flag == True:
	    self.render_area = ((0,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True

    def move_down(self):
        self.direction = Vector2(0,1)
        self.pos += self.direction * self.speed
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*6,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*7,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True

    def move_left(self):
        self.direction = Vector2(-1,0)
        self.pos += self.direction * self.speed
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*2,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*3,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True

    def move_right(self):
        self.direction = Vector2(1,0)
        self.pos += self.direction * self.speed
	if self.render_swap_flag == True:
	    self.render_area = ((self.element_width*4,0),(self.element_width,self.element_height))
	    self.render_swap_flag = False
	else:
	    self.render_area = ((self.element_width*5,0),(self.element_width,self.element_height))
	    self.render_swap_flag = True

    def fire(self):
        print "todo: enemy fire"

    def update(self):
        """generate random movement, or using the A* path finding for movement"""
	self.move_forward()
	if self.hit_wall():
	    self.change_direction()

    def move_forward(self):
        if self.move_direction == 0:
            self.move_up()
        elif self.move_direction == 1:
            self.move_down()
        elif self.move_direction == 2:
            self.move_left()
        elif self.move_direction == 3:
            self.move_right()

    def hit_wall(self):
	if self.pos.x+self.element_width > MAP_WIDTH:
	    self.pos.x = MAP_WIDTH - self.element_width
	    return True
	if self.pos.x < 0:
	    self.pos.x = 0
	    return True
	if self.pos.y < 0:
	    self.pos.y = 0
	    return True
	if self.pos.y+self.element_height > MAP_HEIGHT:
	    self.pos.y = MAP_HEIGHT - self.element_height
	    return True
	return False

    def change_direction(self):
	self.move_direction = random.randrange(4)

    def render(self):
	self.screen.blit(self.image,(self.pos.x,self.pos.y),self.render_area)

	
        

    

    
        
        
