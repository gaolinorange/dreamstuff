from Vector2 import *

import sys

if __name__ == '__main__':
    v1 = Vector2(10,10)
    print "V1: ",v1
    v2 = Vector2(20,20)
    print "V2: ",v2

    v3 = v1 + v2
    print "V1+V2:" , v3

    v4 = v1-v2
    print "V1-V2",v4

    v5 = v2-v1
    print "V2-V1",v5

    magnitude = v1.get_magnitude()
    print "V1 magnitude: ",magnitude

    v1.normalize()
    print v1
    
    
