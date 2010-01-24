from Helpers import *

class Exploration(pygame.sprite.Sprite):
    """Animate the Exploration image sequences
    """
    
    def __init__(self):
        """
        """
	pygame.sprite.Sprite.__init__(self)
	self.image,self.rect = load_image('explore.png',-1)

	self.updateIndex = 0;
	self.element_width = 32;
	self.element_height = 32;
	self.render_area = ((0,0),(self.element_width,self.element_height))


    def updateAnimation(self):
	"""
	"""
	self.updateIndex += 1
	self.render_area = ((self.element_width*self.updateIndex,0),(self.element_width,self.element_height))
	
	if(self.updateIndex == 6):
	    self.updateIndex = 0
	
   	

if __name__ == '__main__':
    exploration = Exploration()

	

	
	    
	

        
        
