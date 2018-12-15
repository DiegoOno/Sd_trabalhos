class EmptyConfigException(Exception):
    def __init__(self, message):
        super().__init__(message)

class ConfigNotFoundException(Exception):
    def __init__(self, message):
        super().__init__(message)

class UnitNotValidException(Exception):
    def __init__(self, message):
        super().__init__(message)

