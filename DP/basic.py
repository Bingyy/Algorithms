
'''
假设你要去野营。你有一个**容量为6磅**的背包，需要决定该携带下面的哪些东西。其中每样东西都有相应的价值，价值越大意味着越重要： 

- 水（重3磅，价值10） 
- 书（重1磅，价值3）
- 食物（重2磅，价值9） 
- 夹克（重2磅，价值5） 
-  相机（重1磅，价值6） 

请问**携带哪些东西时价值最高**？
'''

# DP problem setting
# 

bag = 6

objects = {"water": [3, 10], "book": [1, 3],
			 "food": [2,9], "jack": [2,5],
			 "camera": [1,6]}

cell = [] # 5rows x 6columns values are useful
names = ["water", "book", "food", "jack", "camera"]
flag = [False] * 5 

for i in range(6):
	row = []
	for j in range(7):
		row.append(0)
	cell.append(row)

print(cell)

for i in range(1, len(cell)): # 12345

	for j in range(1, len(cell[0])): # 123456

		# print(i,j)

		current_object_weight = objects[names[i-1]][0]
		current_object_value = objects[names[i-1]][1]

		# print(current_object_weight)
		# print(current_object_value)
		# 如果当前空间装不下现在的物品，则不装
		val = 0
		if j - current_object_weight < 0 :
			val = 0
			cell[i][j] = cell[i-1][j]
		else:
			val = cell[i-1][j - current_object_weight]
			cell[i][j] = max(cell[i-1][j], current_object_value + val ) 
	
def determineWhatObjectsGetSelected(i,j):
	# i is the row index for cell
	# j is the col index for cell
	# the logic is simple, cell[i][j] == cell[i-1][j] ==> ith object selected
	# cell[i][j] != cell[i-1][j] ==> ith object is noe selected
	# go to check cell[i-1][j-current_object_weight]

	if i == 0 or j == 0:
		return 

	else:
		if cell[i][j] == cell[i-1][j]:
			flag[i-2] = True
			determineWhatObjectsGetSelected(i-1, j)
		if cell[i][j] != cell[i-1][j]:
			flag[i-1] = True
			determineWhatObjectsGetSelected(i-1, j-objects[names[i-1]][0])

determineWhatObjectsGetSelected(5,6)

selected = []

for i in range(len(flag)):
	if(flag[i]):
		selected.append(names[i])


print(selected)

