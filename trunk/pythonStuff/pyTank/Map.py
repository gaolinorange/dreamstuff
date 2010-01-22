from Helpers import *


class Map(pygame.sprite.Sprite):
    """
    """
    
    def __init__(self, width,height,element_width,element_height):
        """
        """
	self.width = width
	self.height = height
	self.element_width = element_width
	self.element_height = element_height
	self.col_num = width / element_width
	self.row_num = height / element_height
	"""Construct the map elements"""
	"""self.map_elements = [0] * self.width_element_num;
	for i in self.map_elements:
	    self.map_elements[i] = [0] * self.height_element_num;
	    """
	self.map_elements = []
	for i in range(self.row_num):
	    self.map_elements.append([])
	    for j in range(self.col_num):
		self.map_elements[i].append(0)

    def loadSprites(self):
	pygame.sprite.Sprite.__init__(self)
	self.image,self.rect = load_image('mapelement_main.png',-1)
	
	
		
	    
	""" todo: Set the map elements to user specific""" 
	
    def printMap(self):
	print self.map_elements;


if __name__ == '__main__':
    map = Map(20,20,4,5);
    map.printMap();
        
        
