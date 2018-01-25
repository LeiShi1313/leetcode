from collections import defaultdict
class Solution(object):
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        ret = defaultdict(int)
        if not formula:
            return ret
        elif formula[0] != '(':
            formula = '(' + formula + ')'
        elif formula[0] == '(':
            s = ['(']
            i = 1
            while i < len(formula):
                if formula[i] == '(':
                    s.append('(')
                elif formula[i] == ')':
                    s.pop()
                if not s:
                    break
                i += 1
            if i < len(formula):
                formula = '(' + formula + ')'
        last_pare = []
        last_ele = ''
        last_digit = 1
        i = 0
        while i < len(formula):
            if 'A' <= formula[i] <= 'Z':
                if last_ele:
                    last_pare[-1][last_ele] += last_digit
                    last_ele = ''
                    last_digit = 1
                last_ele = formula[i]
                i += 1
            elif 'a' <= formula[i] <= 'z':
                last_ele += formula[i]
                i += 1
            elif formula[i].isdigit():
                j = i+1
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                last_digit = int(formula[i:j])
                last_pare[-1][last_ele] += last_digit
                last_ele = ''
                last_digit = 1
                i = j
            elif formula[i] == '(':
                if last_ele:
                    last_pare[-1][last_ele] += last_digit
                    last_ele = ''
                    last_digit = 1
                last_pare.append(defaultdict(int))
                i += 1
            elif formula[i] == ')':
                if last_ele:
                    last_pare[-1][last_ele] += last_digit
                    last_ele = ''
                    last_digit = 1
                last_d = last_pare.pop()
                j = i+1
                while j < len(formula) and formula[j].isdigit():
                    j += 1
                t = int(formula[i+1:j]) if j != i+1 else 1
                i = j
                d = last_pare[-1] if last_pare else ret
                for ele, c in last_d.items():
                    d[ele] += c*t

        s = ''
        for k in sorted(ret.keys()):
            s += k+(str(ret[k]) if ret[k]>1 else '')
        return s


if __name__ == '__main__':
    print Solution().countOfAtoms("H2O")
    print Solution().countOfAtoms("(H2O2)")
    print Solution().countOfAtoms("Mg(OH)2")
    print Solution().countOfAtoms("K4(ON(SO3)2)2")
    print Solution().countOfAtoms("(N13O9Be)37(LiC50B35)38(Li33HHBe14He5ON50N)27(H3C)2He14C34Li33C33He15N14N5Li24Li17H28O13H42(HeHe6CO11Li)35(He3O27HO5N21H49O39CH37B3)8(O41He27He46He22He17)12")
