from Helpers import *
from Vector2 import *
import random


class EnemyTank(pygame.sprite.Sprite):

    def __init__(self,screen):
        self.image,self.rect = load_image('enemytank.png',-1)
        self.screen = screen
        self.pos = Vector2(100,100)
        self.direction = Vector2(1,0)
        self.speed = 3
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

    def render(self):
        self.screen.blit(self.image,(self.pos.x,self.pos.y),self.render_area)

    def fire(self):
        print "todo: enemy fire"

    def update_movement(self):
        """generate random movement, or using the A* path finding for movement"""
        print "todo: update_movement"
        move_direction = random.randrange(5)
        if move_direction == 0:
            self.move_up()
        elif move_direction == 1:
            self.move_down()
        elif move_direction == 2:
            self.move_left()
        elif move_direction == 3:
            self.move_right()
	else:
	    self.fire()

	
        

    

    
        
        
