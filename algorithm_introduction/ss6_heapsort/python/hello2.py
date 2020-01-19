import traceback
import sys


try:
    raise ValueError('Error at line {}')
except ValueError as err:
    raise ValueError(str(err).format(10))
except ValueError as err:
    print(traceback.print_exc(file=sys.stdout))
