import math

class Vector2(object):
    """define the vector to represent the pos and direction
    """
    
    def __init__(self, x = 0.0, y = 0.0 ):
        """
        """
	self.x = x
	self.y = y

    def __str__(self):
	return "(%s,%s)"%(self.x,self.y)

    def from_points(P1,P2):
	return Vector2(P2[0]-P1[0],P2[1]-P1[1])
    
    def __add__(self,rhs):
	return Vector2(self.x + rhs.x, self.y + rhs.y)

    def __neg__(self):
	"""
	"""
	return Vector2(-self.x,-self.y)
	

    def __sub__(self,rhs):
	return Vector2(self.x - rhs.x, self.y - rhs.y)

    def __mul__(self,scalar):
	return Vector2(self.x * scalar,	self.y * scalar)

    def get_magnitude(self):
	magnitude = (self.x**2+self.y**2)
	return math.sqrt(magnitude)

    def normalize(self):
	magnitude = self.get_magnitude()
	self.x /= magnitude
	self.y /= magnitude

    def __div__(self,scalar):
	return Vector2(self.x / scalar, self.y / scalar)

    


    

        
