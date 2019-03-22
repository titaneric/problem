def fractionToDecimal(numerator, denominator):
    """
    :type numerator: int
    :type denominator: int
    :rtype: str
    """
    remain_dict = dict()
    quotient, remainder = divmod(numerator, denominator)

    if remainder:
        num_vec = [str(quotient), '.']
        remain_dict[remainder] = len(num_vec)
        dividend = remainder * 10
        while True:
            quotient, remainder = divmod(dividend, denominator)
            num_vec.append(str(quotient))
            if not remainder:
                break
            if remainder in remain_dict:
                num_vec.insert(remain_dict[remainder], "(")
                num_vec.insert(len(num_vec), ")")
                break
            remain_dict[remainder] = len(num_vec)
            dividend = remainder * 10
    else:
        num_vec = [str(quotient)]
    
    return "".join(num_vec)

print(fractionToDecimal(2, 3))
