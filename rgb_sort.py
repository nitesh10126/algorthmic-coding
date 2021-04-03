'''
This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
'''

def assemble_given_char_on_left_inplace(rgb, c, c_ends_on):
  rgb_len = len(rgb)
  i = c_ends_on+1
  while i < rgb_len:
    v = rgb[i]
    if (c == v):
      swap(rgb, c_ends_on+1, i)
      c_ends_on += 1
    i += 1
  return c_ends_on

  
def sort_rgb(rgb):
  if 0 == len(rgb):
    return
  if 1 == len(rgb):
    return
  
  R_ends_on = assemble_given_char_on_left_inplace(rgb, 'R', -1)
  assemble_given_char_on_left_inplace(rgb, 'G', R_ends_on)

  
def swap(rgb, i, j):
  rgb[i], rgb[j] = rgb[j], rgb[i]

      
if __name__ == '__main__':
  rgb = ['B','B', 'G', 'R', 'G', 'R']
  sort_rgb(rgb)
  print(rgb)
