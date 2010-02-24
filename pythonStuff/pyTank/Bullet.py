from Helpers import *
from Vector2 import *
from Settings import *

class Bullet(pygame.sprite.Sprite):

    def __init__(self,surface,pos,direction):
	pygame.sprite.Sprite.__init__(self)
	
        self.image,self.rect = load_image('bullet.png',-1)
        self.alive = True

	self.surface = surface
	self.pos = pos
	self.direction = direction
	self.speed = 1
	self.element_width = 32
	self.element_height = 32

    def set_speed(self,speed):
	self.speed = speed

    def update(self):
	"""update the bullet until it hits the wall or something"""
	self.pos += self.direction * self.speed
	self.rect = (self.pos.x,self.pos.y,self.pos.x+self.element_width,
		     self.pos.y+self.element_height)
	if self.hit_wall():
	    return True

    def render(self):
	self.surface.blit(self.image,self.rect)
    
    def hit_wall(self):
	if self.pos.x > MAP_WIDTH:
	    return True
	if self.pos.x <  0:
	    return True
	if self.pos.y < 0:
	    return True
	if self.pos.y > MAP_HEIGHT:
	    return True

	return False
	
	
