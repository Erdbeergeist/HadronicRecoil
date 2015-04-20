from array import array
import numpy as np
import sys
sys.path.append('/Users/root/lib')
from ROOT import TCanvas,TGraphErrors, gRandom, TGraph ,TF1, TLegend
import csv

def gmax(data):
  h = 0
  i = 0
  for i in range(len(data)):
    if data[i] > h: h = data[i]
  return h

def nooffset(data):
  maxi = gmax(data)
  mini = min(data)
  i = 0
  corr = array("f")
  for i in range(len(data)):
    corr.append((-1)*(data[i])+maxi)
    #corr.append((data[i]))
  return corr

def towavel(chan):
  a = 1265.2789234299905
  b = 0.18498867487378953
  da = 22.025203303269485
  db = 0.0028956591954408467
  i = 0
  corr = array("f")
  dcorr = array("f")
  for i in range(len(chan)):
      corr.append((a+b*chan[i])/1000)
      dcorr.append(np.sqrt((chan[i]*db)**2+(da**2))/1000)
  return corr,dcorr

fwhm = array("d")
maxima = array("d")
sig = array("d")
data1 = array("f")
data2 = array("f")
data3 = array("f")
data4 = array("f")
data5 = array("f")
data6 = array("f")
data7 = array("f")
data8 = array("f")
chan1 = array("f")
chan2 = array("f")
chan3 = array("f")
chan4 = array("f")
chan5 = array("f")
chan6 = array("f")
chan7 = array("f")
chan8 = array("f")
dchan1 = array("f")
dchan2 = array("f")
dchan3 = array("f")
dchan4 = array("f")
dchan5 = array("f")
dchan6 = array("f")
dchan7 = array("f")
dchan8 = array("f")
ddata = array("f")
max = array("d")
dmax = array("d")
y = 4.96511
fi = TF1("abc","gaus")

fhnd = open("allpco2.txt","w+")

h = ""
with open("/home/lukas/FPrakt/30/Daten/ref0mb.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan1.append(float(h))
    h = row[1].replace(",",".")
    data1.append(float(h))

data1 = nooffset(data1)
chan1,dchan1= towavel(chan1)
i = 0
for i in range(len(chan1)):
  ddata.append(0)

c = TCanvas("c","Calibration",200,10,700,500)
#g = TGraphErrors(len(chan1),chan1,data1,dchan1,ddata)
g = TGraph(len(chan1),chan1,data1)
g.SetTitle("")
g.SetMarkerColor(4)
g.SetLineColor(4)
g.SetMarkerStyle(20)
g.SetMarkerSize(0.5)
#g.SetMaximum(4.5)
g.GetXaxis().SetLimits(4.2,4.5)
g.GetXaxis().SetTitle("Wellenlaenge [#mum]")
g.GetYaxis().SetTitle("Intensitaet [V]")
g.Draw("AP")
c.Update()
fi.SetLineColor(4)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  fhnd.write("FWHM ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()

h = ""
with open("/home/lukas/FPrakt/30/Daten/iso60.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan8.append(float(h))
    h = row[1].replace(",",".")
    data8.append(float(h))

data8 = nooffset(data8)
chan8,dchan8 = towavel(chan8)
#g8 = TGraphErrors(len(chan8),chan8,data8,dchan8,ddata)
g8 = TGraph(len(chan8),chan8,data8)
g8.SetMarkerColor(8)
g8.SetLineColor(8)
g8.SetMarkerStyle(20)
g8.SetMarkerSize(0.5)
g8.Draw("P")
c.Update()
fi.SetLineColor(8)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g8.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()

h = ""
with open("/home/lukas/FPrakt/30/Daten/iso2050.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan2.append(float(h))
    h = row[1].replace(",",".")
    data2.append(float(h))

data2 = nooffset(data2)
chan2,dchan2 = towavel(chan2)
#g2 = TGraphErrors(len(chan2),chan2,data2,dchan2,ddata)
g2 = TGraph(len(chan2),chan2,data2)
g2.SetMarkerColor(2)
g2.SetLineColor(2)
g2.SetMarkerStyle(20)
g2.SetMarkerSize(0.5)
g2.Draw("P")
fi.SetLineColor(2)
c.Update()
num = 0
for i in range(int(num)):
    xs = input("Enter Xstart:\t")
    xe = input("Enter Xende:\t")
    fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
    par = g2.Fit("abc","+S","",float(xs),float(xe))
    fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
    fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
    fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
    fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
    c.Update()


h = ""
with open("/home/lukas/FPrakt/30/Daten/iso3040.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan3.append(float(h))
    h = row[1].replace(",",".")
    data3.append(float(h))

data3 = nooffset(data3)
chan3,dchan3 = towavel(chan3)
#g3 = TGraphErrors(len(chan3),chan3,data3,dchan3,ddata)
g3 = TGraph(len(chan3),chan3,data3)
g3.SetMarkerColor(6)
g3.SetLineColor(6)
g3.SetMarkerStyle(20)
g3.SetMarkerSize(0.5)
g3.Draw("P")
c.Update()

fi.SetLineColor(6)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g3.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()

h = ""
with open("/home/lukas/FPrakt/30/Daten/iso80190.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan4.append(float(h))
    h = row[1].replace(",",".")
    data4.append(float(h))

data4 = nooffset(data4)
chan4,dchan4 = towavel(chan4)
#g4 = TGraphErrors(len(chan4),chan4,data4,dchan4,ddata)
g4 = TGraph(len(chan4),chan4,data4)
g4.SetMarkerColor(7)
g4.SetLineColor(7)
g4.SetMarkerStyle(20)
g4.SetMarkerSize(0.5)
g4.Draw("P")
c.Update()
fi.SetLineColor(7)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g4.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()

h = ""
with open("/home/lukas/FPrakt/30/Daten/iso100110.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan5.append(float(h))
    h = row[1].replace(",",".")
    data5.append(float(h))

data5 = nooffset(data5)
chan5,dchan5 = towavel(chan5)
#g5 = TGraphErrors(len(chan5),chan5,data5,dchan5,ddata)
g5 = TGraph(len(chan5),chan5,data5)
g5.SetMarkerColor(5)
g5.SetLineColor(5)
g5.SetMarkerStyle(20)
g5.SetMarkerSize(0.5)
g5.Draw("P")
c.Update()
fi.SetLineColor(5)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g5.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()

h = ""
with open("/home/lukas/FPrakt/30/Daten/iso120150.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan6.append(float(h))
    h = row[1].replace(",",".")
    data6.append(float(h))

data6 = nooffset(data6)
chan6,dchan6 = towavel(chan6)
#g6 = TGraphErrors(len(chan6),chan6,data6,dchan6,ddata)
g6 = TGraph(len(chan6),chan6,data6)
g6.SetMarkerColor(1)
g6.SetLineColor(1)
g6.SetMarkerStyle(20)
g6.SetMarkerSize(0.5)
g6.Draw("P")
c.Update()
fi.SetLineColor(1)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g6.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()

h = ""
with open("/home/lukas/FPrakt/30/Daten/iso150260.txt","r") as file:#read data
  reader = csv.reader(file,delimiter ="\t")
  for row in reader:
    h = row[0].replace(",",".")
    chan7.append(float(h))
    h = row[1].replace(",",".")
    data7.append(float(h))

data7 = nooffset(data7)
chan7,dchan7 = towavel(chan7)
#g7 = TGraphErrors(len(chan7),chan7,data7,dchan7,ddata)
g7 = TGraph(len(chan7),chan7,data7)
g7.SetMarkerColor(9)
g7.SetLineColor(9)
g7.SetMarkerStyle(20)
g7.SetMarkerSize(0.5)
g7.Draw("P")
c.Update()
fi.SetLineColor(9)
num = 0
for i in range(int(num)):
  xs = input("Enter Xstart:\t")
  xe = input("Enter Xende:\t")
  fhnd.write("Maxima area esitmate ... "+str(xs)+"\t"+str(xe)+"\n")
  par = g7.Fit("abc","+S","",float(xs),float(xe))
  fhnd.write("Chi2 ... "+str(par.Chi2())+"\n")
  fhnd.write("const ... "+str(par.Parameter(0))+" +/- "+str(par.ParError(0))+"\n")
  fhnd.write("Mean ... "+str(par.Parameter(1))+" +/- "+str(par.ParError(1))+"\n")
  fhnd.write("Sigma ... "+str(par.Parameter(2))+" +/- "+str(par.ParError(2))+"\n")
  c.Update()


l = TLegend(0.69,0.51,0.88,0.87)
l.SetTextSize(0.02)
l.AddEntry(g,"0 mbar","P")
l.AddEntry(g2,"20-50 mbar","P")
l.AddEntry(g3,"30-40 mbar","P")
l.AddEntry(g8,"60 mbar","P")
l.AddEntry(g4,"80-190 mbar","P")
l.AddEntry(g5,"100-110 mbar","P")
l.AddEntry(g6,"120-150 mbar","P")
l.AddEntry(g7,"150-260 mbar","P")
l.Draw()
c.Update()
a = input("")
c.SaveAs("allpco2.pdf")
