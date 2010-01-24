from Helpers import *


class Map(pygame.sprite.Sprite):
    """ Representing the Game Map
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

	self.constructMapData()
	self.loadSprites()
	self.map_surface = self.generateMapSurface()

    def constructMapData(self):
	"""Construct the map elements"""
	self.map_data = []
	for i in range(self.row_num):
	    self.map_data.append([])
	    for j in range(self.col_num):
		self.map_data[i].append((i+j)%6) #the magic number 6 is the number of map elements
				

    def loadSprites(self):
	pygame.sprite.Sprite.__init__(self)
	self.image,self.rect = load_image('mapelement_main.png',-1)
	"""The image size of map elements and sprites are 32x32"""
	
	self.wall_image = self.image.subsurface((0,0),(self.element_width,self.element_height))
	self.steal_image = self.image.subsurface((self.element_width,0),(self.element_width,self.element_height))
	self.water_image = self.image.subsurface((self.element_width*2,0),(self.element_width,self.element_height))
	self.water2_image = self.image.subsurface((self.element_width*3,0),(self.element_width,self.element_height))
	self.grass_image = self.image.subsurface((self.element_width*4,0),(self.element_width,self.element_height))
	self.edge_image = self.image.subsurface((self.element_width*5,0),(self.element_width,self.element_height))
	    
    def generateMapSurface(self):
	"""
	genreate map surface by using blit
	"""
	map_surface = pygame.Surface((self.width,self.height))
	
	blit_image = self.wall_image #the default blit image
	for i in range(self.row_num):
	    for j in range(self.col_num):
		pos = (i*self.element_width,j*self.element_height)
		if(self.map_data[i][j] == 0):
		    blit_image = self.wall_image
		elif(self.map_data[i][j] == 1):
		    blit_image = self.steal_image;
		elif(self.map_data[i][j] == 2):
		    blit_image = self.water_image;
		elif(self.map_data[i][j] == 3):
		    blit_image = self.water2_image;
		elif(self.map_data[i][j] == 4):
		    blit_image = self.grass_image;
		elif(self.map_data[i][j] == 5):
		    blit_image = self.edge_image;
		
		map_surface.blit(blit_image,pos)
	return map_surface

	
    def printMap(self):
	""" Test Method for print the map data"""
	print self.map_data


if __name__ == '__main__':
    map = Map(320,320,32,32)
    map.printMap();
        
        
