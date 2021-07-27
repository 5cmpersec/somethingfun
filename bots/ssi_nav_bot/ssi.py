import os
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager

from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

def create_webdriver():
    options = Options()
    options.headless = True
    driver = webdriver.Chrome(options=options, executable_path=ChromeDriverManager().install())
    driver.implicitly_wait(20) # seconds
    return driver

class LoginPage:
    def __init__(self, driver):
        self.driver = driver
        self.txtLogin =  WebDriverWait(self.driver, 10).until(
            EC.visibility_of_element_located((By.ID, "name"))
        )
        self.txtPassword =  WebDriverWait(self.driver, 10).until(
            EC.visibility_of_element_located((By.ID, "txtPassword"))
        )
        self.btnLogin =  WebDriverWait(self.driver, 10).until(
            EC.element_to_be_clickable((By.ID, "btnLogin"))
        )

    def login(self, username, password):
        self.txtLogin.clear()
        self.txtLogin.send_keys(username)
        self.txtPassword.clear()
        self.txtPassword.send_keys(password)
        self.btnLogin.click()
        WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "welcome_msg"))
        )
        WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.ID, "tbodyQuote"))
        )
        WebDriverWait(self.driver, 10).until(
            EC.invisibility_of_element_located((By.CLASS_NAME, "loadingtextpanel"))
        )

class CashHistoryPage:
    def __init__(self, driver):
        self.driver = driver
        self.txtFromDate =  WebDriverWait(self.driver, 10).until(
            EC.visibility_of_element_located((By.ID, "fromDate"))
        )
        self.txtToDate =  WebDriverWait(self.driver, 10).until(
            EC.visibility_of_element_located((By.ID, "toDate"))
        )
        self.btnSubmit =  WebDriverWait(self.driver, 10).until(
            EC.element_to_be_clickable((By.ID, "btnSubmit"))
        )
    
    def get_history(self, fromDate, toDate):
        self.txtFromDate.clear()
        self.txtFromDate.send_keys(fromDate)
        self.txtToDate.clear()
        self.txtToDate.send_keys(toDate)
        self.btnSubmit.click()
        table = WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.ID, "tbodyCashTransactionHistory"))
        )
        rows = table.find_elements_by_class_name("trEven")
        for row in rows:
            cls = row.find_elements_by_tag_name('td')
            for c in cls:
                print(c.text)

class PortfolioPage:
    def __init__(self, driver):
        self.driver = driver
        WebDriverWait(self.driver, 10).until(
            EC.invisibility_of_element_located((By.ID, "tbodyBankBalance_Loading"))
        )
        WebDriverWait(self.driver, 10).until(
            EC.invisibility_of_element_located((By.ID, "StockBodyLoading"))
        )
        self.txtSsiNav = WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "equity"))
        )
        self.tblCash = WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.ID, "BankAvailable"))
        )
        self.tblStocks = WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.ID, "StockBody"))
        )
        self.btnNext = WebDriverWait(self.driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "normal"))
        )
    
    def getMarkToMarket(self):
        s = self.txtSsiNav.text
        return int(s[s.find(':')+1:].replace('.', '').strip())

    def getCashBalance(self):
        return int(self.tblCash.text.replace('.', '').strip())
    
    def getPortfolio(self):
        def get_one_page():
            ret = []
            rows = self.tblStocks.find_elements_by_tag_name('tr')
            for row in rows:
                ticker = row.find_element_by_class_name('stock_code_name')
                data = [ticker.text]
                numbers = row.find_elements_by_class_name('text_r')
                for n in numbers:
                    txt = n.text.strip().replace('.', '').replace(',', '.')
                    data.append(txt)
                ret.append(data)
            return ret
        r1 = get_one_page()
        self.btnNext.click()
        WebDriverWait(self.driver, 10).until(
            EC.invisibility_of_element_located((By.ID, "StockBodyLoading"))
        )
        r2 = get_one_page()
        return r1+r2
    
    def getData(self):
        return {
            "MarkToMarket": self.getMarkToMarket(),
            "Cash": self.getCashBalance(),
            "Portfolio": self.getPortfolio(),
        }


class SSI:
    username = os.environ["SSI_USERNAME"]
    password = os.environ["SSI_PASSWORD"]

    def __init__(self):
        self.driver = create_webdriver()
    
    def quit(self):
        self.driver.quit()
    
    def login(self):
        self.driver.get('https://webtrading.ssi.com.vn/Logon')
        loginPage = LoginPage(self.driver)
        loginPage.login(self.username, self.password)
    
    def logout(self):
        self.driver.find_element_by_xpath("//a[@href='Authentication/LogOff']").click()
    
    def get_cash_transaction_history(self, fromDate, toDate):
        self.driver.get('https://webtrading.ssi.com.vn/#CashTransactionHistory')
        cashHistoryPage = CashHistoryPage(self.driver)
        cashHistoryPage.get_history(fromDate, toDate)
    
    def get_portfolio_data(self):
        self.driver.get('https://webtrading.ssi.com.vn/#Portfolio_ListProperties')
        portfolioPage = PortfolioPage(self.driver)
        return portfolioPage.getData()
