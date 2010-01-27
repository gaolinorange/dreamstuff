from Helpers import *

class Bullet(pygame.sprite.Sprite):

    def __init__(self):
        self.image,self.rect = load_image('bullet.png',-1)
        self.alive = True
        
