from Helpers import *


class Tank(pygame.sprite.Sprite):
    """This is our snake that will move around the screen
    """    
    def __init__(self ):
        pygame.sprite.Sprite.__init__(self)
        self.image,self.rect = load_image('tank.png',-1)
        self.lives = 3
	

        
        
