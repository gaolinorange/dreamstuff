from Helpers import *

class Exploration(pygame.sprite.Sprite):
    """Animate the Exploration image sequences
    """
    
    def __init__(self,screen,pos):
        """
        """
	pygame.sprite.Sprite.__init__(self)
	self.image,self.rect = load_image('explore.png',-1)

	self.updateIndex = 0
	self.element_width = 32
	self.element_height = 32
	self.render_area = ((0,0),(self.element_width,self.element_height))
        self.screen = screen
        self.pos = pos
        self.animate_end = False


    def trigger_animate(self):
        self.animate_end = False
        self.updateIndex = 0
        
    def updateAnimation(self):
	"""
	"""
	self.updateIndex += 1
	self.render_area = ((self.element_width*self.updateIndex,0),(self.element_width,self.element_height))
	
	if(self.updateIndex == 6):
	    self.animate_end = True
	
    def render(self):
        if self.animate_end == False:
            self.screen.blit(self.image,self.pos,self.render_area)
        

if __name__ == '__main__':
    exploration = Exploration()

	

	
	    
	

        
        
