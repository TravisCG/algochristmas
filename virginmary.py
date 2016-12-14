def chorus(cly, lt):
	out = []
	for i in range(6):
		txt = cly[0]
		if i % 2 == 1:
			txt = txt.replace("y,", lt)
		out.append(txt)
	out.insert(4, "\n".join([cly[1]] * 2))
	print "\n".join(out) + "\n"

first = ["The Virgin Mary had",
         "The angels sang when",
         "The shepherds came where",
         "The Wise Men saw where"]

endsent = [" a baby boy,", " the baby born"]

second = ["And they say that His name was", 
          "And proclaimed Him the Saviour"]

choruslyr = ["He come from the glory,", "Oh yes, believer!"]

longertag = "ious kingdom."

for i in range(len(first)):

	print "\n".join([first[i] + endsent[i % 4 != 0]] * 3)
	print second[i % 4 == 1] + " Jesus.\n"
	chorus(choruslyr, longertag)
