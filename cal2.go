package main

import "fmt"

var days [12]int = [12]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
var day_of_week [7]string = [7]string{"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"}

func getYear() int{
	var year int
	fmt.Print("西暦を入力してください(2000年以降)：")
	fmt.Scan(&year)

	for year < 2000{
		fmt.Print("2000以上の整数値を入力してください：")
		fmt.Scan(&year)
	}
	return year
}

func getMonth() int{
	var month int
	fmt.Print("月を入力してください：")
	fmt.Scan(&month)

	for month <= 0 || month >= 13{
		fmt.Print("月は1~12までの整数で入力してください：")
		fmt.Scan(&month)
	}
	return month
}

func getDay(y int, m int) int{
	var day int
	fmt.Print("日を入力してください：")
	fmt.Scan(&day)

	for day <= 0 || day > getDays(y, m){
		fmt.Printf("%v年%v月", y, m)

		switch getDays(y, m){
			case 30: fmt.Print("の日は1~30までの整数で入力してください：")
			case 31: fmt.Print("の日は1~31までの整数で入力してください：")
			case 28: fmt.Print("の日は1~28までの整数で入力してください：")
			default: fmt.Print("の日は1~29までの整数で入力してください：")
		}

		fmt.Scan(&day)
	}
	return day
}

func getDays(y int, m int) int{
	var day int

	if isLeapYear(y) == 1{
		if m == 2{
			day = 29
		} else{
			day = days[m-1]
		}
	}	else{
		day = days[m-1]
	}

	return day
}

func isLeapYear(y int) int{
	var flag int

	if y%100 == 0 && y%400 == 0{
		flag = 1
	} else if y%100 == 0 || y%4 != 0{
		flag = 0
	} else{
		flag = 1
	}

	return flag
}

func getDayOfWeekForFirstDay(y int) int{
	y--
	return (y+y/4-y/100+y/400+(13*13+8)/5+1)%7
}

func countDays(y int, m int, d int) int{
	sum := 0

	for i := 1; i < m; i++{
		sum += getDays(y, i)
	}

	sum += d

	return sum
}

func getDayOfWeek(dow int, days int) int{
	return days%7+dow-1
}

func printCalendar(y int, m int, first int){
	sum, count := 0, 0

	for i := 2000; i < y; i++{
		sum += 365+isLeapYear(i)
	}

	for i := 1; i < m; i++{
		sum += getDays(y, i)
	}

	fmt.Printf("%v年%v月\n", y, m)
	fmt.Println(" Sun Mon Tue Wed Thu Fri Sat")

	for i := 0; i < first; i++{
		fmt.Print("    ")
	}

	count += first
	days := getDays(y, m)

	for i := 1; i <= days; i++{
		if count%7 == 0{
			fmt.Print("\n")
		}

		count++
		fmt.Printf("%4v", i)
	}

	fmt.Print("\n")
}

func main(){
	year := getYear()
	month := getMonth()
	day := getDay(year, month)
	dow_first := getDayOfWeekForFirstDay(year)
	days_in_year := countDays(year, month, 1)
	sumDays := countDays(year, month, day)
	dow := getDayOfWeek(dow_first, days_in_year)
	printCalendar(year, month, dow)

	fmt.Printf("%v年%v月%v日はその年の%v日目\n", year, month, day, sumDays)
	fmt.Printf("曜日は %v です\n", day_of_week[getDayOfWeek(dow_first, sumDays)])
}

