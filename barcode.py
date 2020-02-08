def BarCode_1()    :
	n=int(input('hi input here'))
	    if n> 10^10 :
		print('5~10 자리 숫자를 입력하세요')
		return code
	    if n == '0':
	        code = '||::'
	    elif n == '1':
	        code = ':::||'
	    elif n == '2':
	        code ='::|:|'
	    elif n =='3':
	        code = '::||:'
	    elif n =='4':
		code = ':|::|'
	    elif n=='5':
	        code =':|:|:'
	    elif n=='6':
		code =':||::'
	    elif n=='7':
		code ='|:::|'
	    elif n == '8':
	        code = '|::|:'
	    elif n =='9':
	        code ='|:|::'
	    else:
	        code ='오류!'
    return code


