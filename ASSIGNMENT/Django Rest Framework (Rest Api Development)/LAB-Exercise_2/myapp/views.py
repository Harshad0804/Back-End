from urllib import request, response
from django.shortcuts import render
import requests

# Create your views here.
def index(request):
    if request.method == 'POST':
        url="http://localhost:8000/api/books"
        querystring={'title': request.POST['title'], 'author':request.POST['author'], 'isbn':request.POST['isbn'], 'publisher': request.POST['publisher']}
        response=requests.post(url,json=querystring)
        print(response)
        msg="Data Inserted Successfully"
        response=requests.get(url)
        data=response.json()
        return render(request, 'index.html', {'msg': msg, 'data': data})
    else:
        url="http://localhost:8000/api/books"
        response=requests.get(url) 
        data=response.json()
        return render(request, 'index.html',{'data':data})