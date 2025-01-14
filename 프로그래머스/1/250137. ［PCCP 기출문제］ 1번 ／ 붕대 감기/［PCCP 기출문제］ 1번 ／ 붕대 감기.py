def solution(bandage, health, attacks):
    now_health = health
    heal_count = 0
    attacks_num = 0
    num  = attacks[len(attacks)-1][0]
    
    for i in range(num+1):
        if i == attacks[attacks_num][0]:
            now_health = now_health - attacks[attacks_num][1]
            heal_count = 0
            attacks_num+=1
        
        else:
            heal_count += 1
            now_health += bandage[1]
            if heal_count == bandage[0]:
                heal_count = 0 # 연속 회복 초기화
                now_health += bandage[2] # 추가 회복
                
            now_health = min(now_health, health) # 최대체력 넘으면 최대체력으로
                
            # if (now_health <= health) & (now_health + bandage[1] <= health):
            #     now_health += bandage[1]
            #     if (heal_count == bandage[0]) & (now_health + bandage[2] <= health):
            #         now_health += bandage[2]
            #         heal_count = 0
                    
        if now_health <= 0:
            return -1
        
    return now_health
