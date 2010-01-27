from Helpers import *
import random


class EnemyTank(pygame.sprite.Sprite):

    def __init__(self,screen):
        self.image,self.rect = load_image('enemytank.png',-1)
        self.screen = screen
        self.pos = Vector2(100,100)

    def move_up(self):
        self.pos += Vector2(0,-1)

    def move_down(self):
        self.pos += Vector2(0,1)

    def move_left(self):
        self.pos += Vector2(-1,0)

    def move_right(self):
        self.pos += Vector2(1,0)

    def render(self):
        self.screen.blit(self.image,(self.pos.x,self.pos.y))

    def fire(self):
        print "todo: enemy fire"

    def update_movement(self):
        """generate random movement, or using the A* path finding for movement"""
        print "todo: update_movement"
        move_direction = random.randrange(4)
        if move_direction == 0:
            move_up()
        elif move_direction = 1:
            move_down()
        elif move_direction = 2:
            move_left()
        elif move_direction = 3:
            move_right()
        

    

    
        
        
