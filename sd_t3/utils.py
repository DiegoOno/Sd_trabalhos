from configs import *
from Exceptions import *

VALID_UNITS = ['metric', 'imperial', 'default']

def isStringEmpty(string):
    if ((string != None) and (len(string) != 0)):
        return False
    return True

def checkConfigs():
    print()

    print('Looking for API_KEY... ')
    if ('API_KEY' not in globals()):
        raise ConfigNotFoundException('API_KEY not found in configs.py')
    if (isStringEmpty(API_KEY)):
        raise EmptyConfigException('API_KEY cannot be empty.')
    else:
        print('API_KEY found!\n')

    print('Looking for URL... ')
    if ('URL' not in globals()):
        raise ConfigNotFoundException('URL not found in configs.py')
    if (isStringEmpty(URL)):
        raise EmptyConfigException('URL cannot be empty.')
    else:
        print('URL found: ' + URL + '\n')
    
    emptyCityName = False

    print('Looking for CITY_NAME... ')
    if ('CITY_NAME' not in globals()):
        raise ConfigNotFoundException('CITY_NAME not found in configs.py')
    if (isStringEmpty(URL)):
        print('CITY_NAME is not defined. \n')
        emptyCityName = True
    else:
        print('CITY_NAME found: ' + CITY_NAME + '\n')

    print('Looking for CITY_ID... ')
    if ('CITY_ID' not in globals()):
        raise ConfigNotFoundException('CITY_ID not found in configs.py')
    if (isStringEmpty(URL)):
        if (emptyCityName):
            raise EmptyConfigException('CITY_NAME and CITY_ID cannot be empty. At least one must be defined.')
        else:
            print('CITY_ID if not defined. \n')

    else:
        print('CITY_ID found: ' + CITY_ID + '\n')

    print('Looking for UNITS... ')
    if ('UNITS' not in globals()):
        raise ConfigNotFoundException('UNITS not found in configs.py')
    if (isStringEmpty(URL)):
        print('UNITS is not defined. The default value will be used.\n')
        emptyCityName = True
    else:
        if (UNITS not in VALID_UNITS):
            raise UnitNotValidException(UNIT + ' is not valid. Valid values for UNIT are: ' + VALID_UNITS)

    print("Done! Configuration file is OK!")
    print()

checkConfigs()
