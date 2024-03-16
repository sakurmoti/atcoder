import re
print('Yes' if re.match(r'^<[=]+>$', input()) else 'No')