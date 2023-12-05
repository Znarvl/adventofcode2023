thresholds = {"red": 12, "blue": 14, "green": 13}

accepted_games = []

with open("input.txt") as file:
    for item in file:
        item = item.split()
        item = [element.replace(":", "").replace(";", "").replace(",", "") for element in item]

        threshold_is_below = True

        for i in item:
            if i.isdigit():
                previous_number = int(i)
            if i.lower() in thresholds:
                # If the item is a color
                color = i.lower()
                if previous_number is not None:
                    color_threshold = thresholds[color]
                    if previous_number > color_threshold:
                        threshold_is_below = False
                        break
                    
        if threshold_is_below:
            accepted_games.append(int(item[1]))

print(sum(accepted_games))
