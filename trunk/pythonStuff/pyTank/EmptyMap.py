import pygame

class EmptyMap(object):
    """
    """
    
    def __init__(self, screen,width,height):
        """
        """
	self.screen = screen
	self.width = width
	self.height = height
	self.map_surface = pygame.Surface((self.width,self.height))
	self.map_surface.fill(pygame.Color(0,0,0))

    def render(self):
	"""
	"""
	self.screen.blit(self.map_surface,((0,0),(self.width,self.height)))
	
	

	
        
        
