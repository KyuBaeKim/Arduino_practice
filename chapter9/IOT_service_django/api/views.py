import contextlib
from django.shortcuts import render
from django.http import JsonResponse
from mqtt.models import Sensors
# Create your views here.


#http://localhost:8000/api/greet/?name=hong&age=30
def greet(request):
    name = request.GET.get('name', '없음')
    age = int(request.GET.get('age', 0))
    context = {
        'name' : name,
        'age' : age,
        'address' :'서울시',
    }
    
    return render(request, 'greet.html', context)
    # return JsonResponse(context) #JSON으로 응답


#http://localhost:8000/api/greet/?sensor?sensor=temp

def sensor_list(request):

    sensor = request.GET.get('sensor')
    
    values = Sensors.objects.filter(sensor=sensor)
    print(values)
    
    return JsonResponse({})